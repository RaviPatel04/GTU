// Write a JavaScript program function that calculates days remaining till your birthday.


function calculateDays() {
    let birthdate = new Date(document.getElementById('birth-date').value);
    
    let currentDate = new Date();
   

    let currentYearBirthday = new Date(currentDate.getFullYear(), birthdate.getMonth(), birthdate.getDate());

    if (currentDate > currentYearBirthday) {
        currentYearBirthday.setFullYear(currentDate.getFullYear() + 1);
    }

    let oneDay = 24 * 60 * 60 * 1000;
    let daysRemaining = Math.round((currentYearBirthday - currentDate) / oneDay);

    document.getElementById('result').innerText = `Days remaining until your birthday: ${daysRemaining}`;
}
