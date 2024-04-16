// For the form created in HTML provide various form values checking passed by user.


function validateForm() {

    let usernameValue = document.getElementById("username").value;
    let passwordValue = document.getElementById("password").value;
    let emailValue = document.getElementById("email").value;
    let numberValue = document.getElementById("number").value;
    let textareaValue = document.getElementById("textarea").value;
    let dateValue = document.getElementById("date").value;
    let genderValue = document.querySelector('input[name="gender"]:checked');
    let fileValue = document.getElementById("file").value;
    let checkboxChecked = document.getElementById("checkbox").checked;

    let isValid = true;

    if (usernameValue === "") {
        setError('usernameError', 'Username cannot be empty');
        isValid = false;
    } else {
        setError('usernameError', '');
    }

    if (passwordValue.length < 8) {
        setError('passwordError', 'Minimum 8 characters are required in Password');
        isValid = false;
    } else {
        setError('passwordError', '');
    }

    let emailRegex = /^[a-zA-Z0-9+._]+@[0-9a-zA-Z]+\.[a-zA-Z]{2,3}$/;
    if (!emailRegex.test(emailValue)) {
        setError('emailError', 'Please enter a valid email');
        isValid = false;
    } else {
        setError('emailError', '');
    }

    if (numberValue === "" || isNaN(numberValue)) {
        setError('numberError', 'Please enter a valid number');
        isValid = false;
    } else {
        setError('numberError', '');
    }

    if (textareaValue === "") {
        setError('textareaError', 'Description cannot be empty');
        isValid = false;
    } else {
        setError('textareaError', '');
    }

    if (dateValue === "") {
        setError('dateError', 'Please select a date');
        isValid = false;
    } else {
        setError('dateError', '');
    }

    if (!genderValue) {
        setError('genderError', 'Please select a gender');
        isValid = false;
    } else {
        setError('genderError', '');
    }

    if (fileValue === "") {
        setError('fileError', 'Please upload a file');
        isValid = false;
    } else {
        setError('fileError', '');
    }

    if (!checkboxChecked) {
        setError('checkboxError', 'Please agree to the terms and conditions');
        isValid = false;
    } else {
        setError('checkboxError', '');
    }

    return isValid;
}

function setError(id, message) {
    const errorElement = document.getElementById(id);
    errorElement.textContent = message;
}