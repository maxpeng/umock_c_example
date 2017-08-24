#include "testrunnerswitcher.h"
#include "umock_c.h"

#define ENABLE_MOCKS
    #include "square_root.h"
#undef ENABLE_MOCKS

#include "pythagorean.h"

DEFINE_ENUM_STRINGS(UMOCK_C_ERROR_CODE, UMOCK_C_ERROR_CODE_VALUES)

static void on_umock_c_error(UMOCK_C_ERROR_CODE error_code)
{
    char temp_str[256];
    (void)snprintf(temp_str, sizeof(temp_str), "umock_c reported error :%d", ENUM_TO_STRING(UMOCK_C_ERROR_CODE, error_code));
    ASSERT_FAIL(temp_str);
}

////////////////////////////////////////////////////////////////////////////////
BEGIN_TEST_SUITE(PythagoreanTest)

TEST_SUITE_INITIALIZE(suite_init)
{
    umock_c_init(on_umock_c_error);
}


TEST_SUITE_CLEANUP(suite_cleanup)
{
    umock_c_deinit();
}


TEST_FUNCTION(my_first_test)
{
    // test 1
    // arrange
    STRICT_EXPECTED_CALL(SquareRoot_sqrt(25))
         .SetReturn(5.0f);

    // act
    float hypotenuse = Pythagorean_hypotenuse(3, 4);

    // assert
    ASSERT_ARE_EQUAL(float, 5.0, hypotenuse);
    ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls(), hypotenuse);

    // reset all calls.
    umock_c_reset_all_calls();

    // test 2
    // arrange
    STRICT_EXPECTED_CALL(SquareRoot_sqrt(2*2 + 3*3))
            .SetReturn(4.0f);

    // act
    hypotenuse = Pythagorean_hypotenuse(2, 3);

    // assert
    ASSERT_ARE_EQUAL(float, 4.0, hypotenuse);
    ASSERT_ARE_EQUAL(char_ptr, umock_c_get_expected_calls(), umock_c_get_actual_calls(), hypotenuse);
}


END_TEST_SUITE(PythagoreanTest)
////////////////////////////////////////////////////////////////////////////////
