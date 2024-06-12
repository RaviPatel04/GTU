public class pr11MVC {
    public static void main(String[] args) {
        pr11Student student = new pr11Student(76,123, 6, 8);
        pr11StudentView studentView = new pr11StudentView();
        pr11StudentController studentController = new pr11StudentController(student, studentView);
        studentController.setSemester(6);
        studentController.setSpi(8);
        studentController.updateView();
    }
}