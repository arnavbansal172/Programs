function validateZipCode(zipCode) {
    const regex = /^\d{6}/;
    return regex.test(zipCode);
}

function validateEmail(email) {
    const regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return regex.test(email);
}

function validatePhoneNumber(phoneNumber) {
    const regex = /^\d{10}$/;
    return regex.test(phoneNumber);
}

// tests
const zipcodeTests = []
const emailTests = []
const phoneNumberTests = []

zipcodeTests.push(validateZipCode('560078'));
zipcodeTests.push(!validateZipCode('A56008'));

emailTests.push(validateEmail('manomay@mail.com'));
emailTests.push(!validateEmail('manomay@mail'));

phoneNumberTests.push(validatePhoneNumber('9988765654'));
phoneNumberTests.push(!validatePhoneNumber('9Z98876565'));

console.log(zipcodeTests.every(test => test)? 'All tests passed': 'Some tests failed');