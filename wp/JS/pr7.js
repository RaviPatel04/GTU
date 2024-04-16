// Write down simple JavaScript using timeout such that image will be changed after every 1 ms at a specified position.

const images = ["n1.jpg", "n2.jpg", "n3.png"];
let currentIndex = 0;

function changeImage() {
    document.getElementById("image").src = images[currentIndex];
    currentIndex = (currentIndex + 1) % images.length;
    setTimeout(changeImage, 1);
}
changeImage();