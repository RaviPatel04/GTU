
public class StudentView {
    public void displayStudentDetails(Student student) {
        System.out.println("Student Details: ");
        System.out.println("Student ID: " + student.getStudentId());
        System.out.println("Enrollment No.: " + student.getEnrollmentNumber());
        System.out.println("Semester: " + student.getSemester());
        System.out.println("SPI: " + student.getSpi());
    }
}
