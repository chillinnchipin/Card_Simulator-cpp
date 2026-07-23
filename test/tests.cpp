#include <argparse/argparse.hpp>
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
// #include <CUnit/CUCurses.h>
#include <string>
#include <iostream>
#include <vector>
#include "test_card.cpp"
using std::cerr;
using std::cout;
using std::endl;
using std::exit;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    argparse::ArgumentParser program("test_cardsim");

    // Add positional arguments
    program.add_argument("mode")
        .help("The CUNIT test mode to run the test in. Automated Basic Console Curses");

    // Add optional helper arguments
    program.add_argument("--verbose", "-V")
        .help("Turn on verbose outputs on CUNIT and custom testing code")
        .flag();

    // Parse arguments
    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception &err)
    {
        cerr << err.what() << std::endl;
        cerr << program; // FIXME this works on the guide by the operand types don't match
        exit(1);
    }

    // Setup test registry
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        cerr << "Failed to initialize CUnit test registry." << endl;
        exit(1);
    }

    // Add test suites to registry
    vector<CU_pSuite> testSuites;
    testSuites.push_back(CU_add_suite("Test Card Suite", setup_Card_test_suite, cleanup_Card_test_suite));
    testSuites.push_back(CU_add_suite("Test Playing Card Suite", setup_PlayingCard_test_suite, cleanup_PlayingCard_test_suite));
    // Check all suites have been added correctly
    for (auto &suite : testSuites)
    {
        if (suite == nullptr)
        {
            cerr << "Failed to add test suite: " << CU_get_error_msg() << endl;
            CU_cleanup_registry();
            exit(1);
        }
    }

    // Add test cases to suites
    vector<CU_pTest> testCases;
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card Default Constructor", test_Card_default_constructor));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card Constructor", test_Card_constructor));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card get_suit", test_Card_get_suit));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card get_value", test_Card_get_value));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card set_suit", test_Card_set_suit));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card set_value", test_Card_set_value));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card operator==", test_Card_operator_eq));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card operator<", test_Card_operator_lt));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card operator>", test_Card_operator_gt));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card operator=", test_Card_operator_assign));
    testCases.push_back(CU_add_test(testSuites.at(0), "Test Card operator+", test_Card_operator_add));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card Default Constructor", test_PlayingCard_default_constructor));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card Constructor", test_PlayingCard_constructor));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card get_suit", test_PlayingCard_get_suit));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card get_value", test_PlayingCard_get_value));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card set_suit", test_PlayingCard_set_suit));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card set_value", test_PlayingCard_set_value));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card int_to_suit", test_PlayingCard_int_to_suit));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card string_to_suit", test_PlayingCard_string_to_suit));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card int_to_value", test_PlayingCard_int_to_value));
    testCases.push_back(CU_add_test(testSuites.at(1), "Test Playing Card string_to_value", test_PlayingCard_string_to_value));

    // Run test based on settings
    /// @brief an enumeration of all of the available testing modes through CUNIT
    enum Test_Mode
    {
        Automated,
        Basic,
        Console,
        Curses,
    };

    // FIXME: get the string from the argument parser and convert it to the enum type
    // Test_Mode mode = program.get<string>("mode");

    /*switch (mode) {
        case Test_Mode::Automated:
            // Run automated tests
            CU_automated_run_tests();
            break;
        case Test_Mode::Basic:
            // Run basic tests
            CU_basic_run_tests();
            break;
        case Test_Mode::Console:
            // Run console tests
            CU_console_run_tests();
            break;
        case Test_Mode::Curses:
            // Run curses tests
            //CU_curses_run_tests();
            std::cerr << "Curses mode is currently not supported. Please use another mode." << std::endl;
            return 1;
        default:
            std::cerr << "Invalid test mode: " << mode << std::endl;
            return 1;
    }*/

    string mode = program.get<string>("mode");
    // FIXME: none of the run_test() functions are defined in the CUnit library.
    if (mode == "Automated")
    {
        CU_automated_run_tests();
    }
    else if (mode == "Basic")
    {
        CU_basic_run_tests();
    }
    else if (mode == "Console")
    {
        CU_console_run_tests();
    }
    else if (mode == "Curses")
    {
        // CU_curses_run_tests(); //FIXME CUCureses.h is not included in the libcunit1 package, causing CU_curses_run_tests() to be undefined.
        cerr << "Curses mode is currently not supported. Please use another mode." << endl;
        exit(1);
    }
    else
    {
        cerr << "Invalid test mode: " << mode << endl;
        exit(1);
    }

    // Print test summary
    auto summary = CU_get_run_summary();
    cout << "Tests run: " << summary->nTestsRun << endl
         << "Tests failed: " << summary->nTestsFailed << endl
         << "Assertions run: " << summary->nAsserts << endl
         << "Assertions failed: " << summary->nAssertsFailed << endl;
    auto failures = CU_get_failure_list();
    if (failures != nullptr)
    {
        cout << "Failed tests:" << endl;
        for (auto failure = failures; failure != nullptr; failure = failure->pNext)
        {
            cout << "  " << failure->pTest->pName << ": " << failure->strCondition << endl;
        }
    }

    // Cleanup test registry
    CU_cleanup_registry();

    return 0;
}