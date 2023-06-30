#include "Application.h" // Include the header file for application

#define Passlength 4 // Define the length of the password

// Function prototypes
uint8 CheckPassword(uint8 UserPasswordArr[], uint8 PasswordArr[], uint8 length);
void ReturnLength(uint8 FirstOperand[], uint8 secondOperand[], uint8 *count1, uint8 *count2);
double OperationFunc(uint8 Operator, uint32 operand1, uint32 operand2);
float DoDiv(uint32 operand1, uint32 operand2);
uint32 DoSum(uint32 operand1, uint32 operand2);
uint32 DoSub(uint32 operand1, uint32 operand2);
uint32 DoMul(uint32 operand1, uint32 operand2);
void calculator(void);

int main() {
    // Variable declarations and initializations
    uint8 KpValue = 'A';
    uint8 counter = ZERO_INIT;
    uint8 l_counter = ZERO_INIT;
    uint8 RetVal = ZERO_INIT;
    uint8 PasswordArr[4] = {1, 1, 1, 2};
    uint8 UserPasswordArr[4] = {0};
    Std_ReturnType ret = E_NOT_OK;

    application_initializations(); // Call application initialization function

    // Display setup message on the LCD
    H_LCD_4BIT_SEND_STRING_POS(&_4BIT_LCD, "Calculator Setup", 2, 3);
    _delay_ms(500);

    ret = H_LCD_4BIT_SEND_COMM(&_4BIT_LCD, CLR_DISPLAY); // Clear the LCD display
    H_LCD_4BIT_SEND_STRING_POS(&_4BIT_LCD, "Loading", 1, 1);

    // Display loading animation
    for (counter = 0; counter < 7; counter++) {
        H_LCD_4BIT_SEND_DATA_POS(&_4BIT_LCD, 1, counter + 8, '.');
        _delay_ms(100);
    }

    _delay_ms(200);
    H_LCD_4BIT_SEND_COMM(&_4BIT_LCD, _LCD_CLEAR);
    _delay_ms(50);

    // Main program loop
    while (1) {
        H_LCD_4BIT_SEND_STRING_POS(&_4BIT_LCD, "User Password:", 1, 1);

        // Read keypad input until a valid key is pressed
        do {
            KpValue = keypad_read_value(&KEYPADMATRIX);
            _delay_ms(20);
        } while (KpValue == 'A');

        H_LCD_4BIT_SEND_DATA_POS(&_4BIT_LCD, 1, l_counter + 15, '*');
        UserPasswordArr[l_counter] = KpValue;
        l_counter += 1;

        if (KpValue == 'C') {
            H_LCD_4BIT_SEND_COMM(&_4BIT_LCD, _LCD_CLEAR);
            _delay_ms(50);

            // Check the entered password
            RetVal = CheckPassword(UserPasswordArr, PasswordArr, Passlength);

            if (RetVal == 1) {
                H_LCD_4BIT_SEND_COMM(&_4BIT_LCD, _LCD_CLEAR);
                _delay_ms(50);
                H_LCD_4BIT_SEND_STRING_POS(&_4BIT_LCD, "Logging in", 1, 1);

                // Display login animation
                for (int count = 0; count < 7; count++) {
                    H_LCD_4BIT_SEND_DATA_POS(&_4BIT_LCD, 1, count + 11, '.');
                    _delay_ms(100);
                }

                H_LCD_4BIT_SEND_STRING_POS(&_4BIT_LCD, "Welcome, Ibrahem", 2, 3);
                _delay_ms(1000);
                H_LCD_4BIT_SEND_COMM(&_4BIT_LCD, _LCD_CLEAR);
                _delay_ms(50);
                l_counter = 0;

                // Calculator loop
                while (1) {
                    calculator(); // Call calculator function

                    KpValue = 'A';
                    do {
                        KpValue = keypad_read_value(&KEYPADMATRIX);
                        _delay_ms(20);
                    } while (KpValue == 'A');

                    _delay_ms(50);
                    H_LCD_4BIT_SEND_COMM(&_4BIT_LCD, _LCD_CLEAR);
                }
            } else {
                H_LCD_4BIT_SEND_COMM(&_4BIT_LCD, _LCD_CLEAR);
                _delay_ms(100);
                H_LCD_4BIT_SEND_STRING_POS(&_4BIT_LCD, "Wrong Password ..", 1, 1);
                _delay_ms(1000);
                H_LCD_4BIT_SEND_COMM(&_4BIT_LCD, _LCD_CLEAR);
                l_counter = 0;
            }
        }
        KpValue = 'A';
    }

    return 0;
}

// Function to initialize the application
void application_initializations(void) {
    HAL_initializations(); // Call HAL initialization function
}

// Function to perform calculator operations
void calculator(void) {
    // Variable declarations and initializations
    uint32 operand1 = ZERO_INIT;
    uint32 operand2 = ZERO_INIT;
    uint8 count1 = ZERO_INIT;
    uint8 count2 = ZERO_INIT;
    uint8 KpOperands = 'A';
    uint8 FirstOperand[10] = {0};
    uint8 secondOperand[10] = {0};
    uint8 Arr1Counter = ZERO_INIT;
    uint8 Arr2Counter = ZERO_INIT;
    uint8 l_counter = 1;
    double Result = ZERO_INIT;
    uint8 operand = ZERO_INIT;

    // Read first operand and operator
    while (1) {
        do {
            KpOperands = keypad_read_value(&KEYPADMATRIX);
            _delay_ms(50);
        } while (KpOperands == 'A');

        if (KpOperands == '+' || KpOperands == '/' || KpOperands == '*' || KpOperands == '-') {
            operand = KpOperands;
            H_LCD_4BIT_SEND_DATA_POS(&_4BIT_LCD, 1, l_counter, operand);
            l_counter += 1;
            break;
        }

        H_LCD_4BIT_SEND_NUMBER_POS(&_4BIT_LCD, KpOperands, 1, l_counter);
        FirstOperand[Arr1Counter] = KpOperands;
        Arr1Counter++;
        l_counter += 1;
    }

    // Read second operand and perform calculation
    while (1) {
        KpOperands = 'A';
        do {
            KpOperands = keypad_read_value(&KEYPADMATRIX);
            _delay_ms(50);
        } while (KpOperands == 'A');

        if (KpOperands == '=') {
            H_LCD_4BIT_SEND_DATA_POS(&_4BIT_LCD, 1, l_counter, '=');

            ReturnLength(FirstOperand, secondOperand, &count1, &count2);

            for (int i = 0; i < count1; i++) {
                operand1 = operand1 * 10 + FirstOperand[i];
            }

            for (int i = 0; i < count2; i++) {
                operand2 = operand2 * 10 + secondOperand[i];
            }

            Result = OperationFunc(operand, operand1, operand2);
            l_counter += 1;
            break;
        }

        H_LCD_4BIT_SEND_NUMBER_POS(&_4BIT_LCD, KpOperands, 1, l_counter);
        secondOperand[Arr2Counter] = KpOperands;
        Arr2Counter++;
        l_counter += 1;
    }

    // Display the result on the LCD
    if (operand2 == 0) {
        H_LCD_4BIT_SEND_STRING_POS(&_4BIT_LCD, "INFINITY !!", 1, l_counter);
        _delay_ms(100);
    } else {
        H_LCD_4BIT_SEND_FNUMBER_POS(&_4BIT_LCD, Result, 1, l_counter);
    }
}

// Function to check the user's password
uint8 CheckPassword(uint8 UserPasswordArr[], uint8 PasswordArr[], uint8 length) {
    uint8 retVal = 1; // Assume the password is correct initially

    for (int i = 0; i < length; i++) {
        if (UserPasswordArr[i] != PasswordArr[i]) {
            retVal = 0; // Set retVal to 0 if a mismatch is found
            break; // Exit the loop
        }
    }

    return retVal;
}

// Function to perform the requested operation
double OperationFunc(uint8 Operator, uint32 operand1, uint32 operand2) {
    double retVal = 0;

    switch (Operator) {
        case '+':
            retVal = DoSum(operand1, operand2);
            break;
        case '-':
            retVal = DoSub(operand1, operand2);
            break;
        case '*':
            retVal = DoMul(operand1, operand2);
            break;
        case '/':
            retVal = DoDiv(operand1, operand2);
            break;
    }

    return retVal;
}

// Function to perform addition
uint32 DoSum(uint32 operand1, uint32 operand2) {
    return (operand1 + operand2);
}

// Function to perform subtraction
uint32 DoSub(uint32 operand1, uint32 operand2) {
    return (operand1 - operand2);
}

// Function to perform multiplication
uint32 DoMul(uint32 operand1, uint32 operand2) {
    return (operand1 * operand2);
}

// Function to perform division
float DoDiv(uint32 operand1, uint32 operand2) {
    return ((float)operand1 / (float)operand2);
}

// Function to return the length of the operands
void ReturnLength(uint8 FirstOperand[], uint8 secondOperand[], uint8 *count1, uint8 *count2) {
    while (FirstOperand[*count1] != '\0') {
        *count1 += 1;
    }

    while (secondOperand[*count2] != '\0') {
        *count2 += 1;
    }
}
