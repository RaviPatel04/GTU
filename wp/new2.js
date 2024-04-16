document.getElementById('regForm').addEventListener('submit', function(event) {
  var username = document.getElementById('username').value.trim();
  var password = document.getElementById('password').value.trim();
  var gender = document.querySelector('input[name="gender"]:checked');
  var phone = document.getElementById('phone').value.trim();
  
  if (username === '') {
    alert('Please enter your username.');
    event.preventDefault();
    return false;
  }
 
  if (password === '') {
    alert('Please enter your password.');
    event.preventDefault();
    return false;
  }
 
  if (!gender) {
    alert('Please select your gender.');
    event.preventDefault();
    return false;
  }
 
  if (phone.length < 10) {
    alert('Please enter a valid phone number of 10 digits');
    event.preventDefault();
    return false;
  }
 
  alert('Form submitted successfully!');
});