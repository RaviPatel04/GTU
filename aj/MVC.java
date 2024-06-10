public class MVC {
    public static void main(String[] args) {
        Student student = new Student(43, 25, 6, 7.40);
        StudentView studentView = new StudentView();
        StudentController studentController = new StudentController(student, studentView);
        studentController.setSemester(6);
        studentController.setSpi(7.40);
        studentController.updateView();
    }
}