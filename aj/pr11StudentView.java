
public class pr11StudentView {
    public void displayStudentDetails(pr11Student student) {
        System.out.println("Student Details: ");
        System.out.println("Student ID: " + student.getStudentId());
        System.out.println("Enrollment No.: " + student.getEnrollmentNumber());
        System.out.println("Semester: " + student.getSemester());
        System.out.println("SPI: " + student.getSpi());
    }
}
