public class MVC {
    public static void main(String[] args) {
        Student student = new Student(76, 23, 6, 8.78);
        StudentView studentView = new StudentView();
        StudentController studentController = new StudentController(student, studentView);
        studentController.setSemester(6);
        studentController.setSpi(8.78);
        studentController.updateView();
    }
}