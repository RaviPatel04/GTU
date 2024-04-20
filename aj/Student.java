
public class Student {
    private int studentId;
    private int enrollmentNumber;
    private int semester;
    private double spi;

    public Student(int studentId, int enrollmentNumber, int semester, double spi) {
        this.studentId = studentId;
        this.enrollmentNumber = enrollmentNumber;
        this.semester = semester;
        this.spi = spi;
    }

    public int getStudentId() {
        return studentId;
    }

    public void setStudentId(int studentId) {
        this.studentId = studentId;
    }

    public int getEnrollmentNumber() {
        return enrollmentNumber;
    }

    public void setEnrollmentNumber(int enrollmentNumber) {
        this.enrollmentNumber = enrollmentNumber;
    }

    public int getSemester() {
        return semester;
    }

    public void setSemester(int semester) {
        this.semester = semester;
    }

    public double getSpi() {
        return spi;
    }

    public void setSpi(double spi) {
        this.spi = spi;
    }
}
