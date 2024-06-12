// database name xyz
// CREATE TABLE STUDENT (
//     eno INT PRIMARY KEY,
//     name VARCHAR(50),
//     sem INT,
//     dept VARCHAR(50),
//     cgpi FLOAT
// );



import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class pr2databaseinsertrecieve {

    private static final String INSERT_STUDENT_QUERY = "INSERT INTO STUDENT VALUES(?,?,?,?,?)";

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);
                Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/xyz", "root", "");
                PreparedStatement ps = con.prepareStatement(INSERT_STUDENT_QUERY);
                Statement stmt = con.createStatement()) {

            int count = 0;
            if (sc != null) {
                System.out.print("How Many Students You Want to Enter: ");
                count = sc.nextInt();
            }

            if (sc != null && ps != null) {
                for (int i = 1; i <= count; i++) {
                    System.out.println("Enter " + i + " Student details");
                    System.out.print("Enter Enrollment number: ");
                    int eno = sc.nextInt();
                    System.out.print("Enter Student Name: ");
                    String name = sc.next();
                    System.out.print("Enter Student Sem: ");
                    int sem = sc.nextInt();
                    System.out.print("Enter Student Department: ");
                    String dept = sc.next();
                    System.out.print("Enter Student CGPI: ");
                    float cgpi = sc.nextFloat();

                    ps.setInt(1, eno);
                    ps.setString(2, name);
                    ps.setInt(3, sem);
                    ps.setString(4, dept);
                    ps.setFloat(5, cgpi);

                    int result = ps.executeUpdate();
                    if (result == 0) {
                        System.out.println(i + "\nStudent record is not inserted\n");
                    } else {
                        System.out.println(i + "\nStudent record Successfully inserted\n");
                    }
                }
            }

            ResultSet rs = stmt.executeQuery("SELECT * FROM STUDENT");
            System.out.println("\t\tStudent Table");
            System.out.println("---------------------------------------------");
            System.out.println("EnNo \tName \tSem \tDEPARTMENT \tCGPI");

            while (rs.next()) {
                System.out.print(rs.getInt("eno") + "\t");
                System.out.print(rs.getString("name") + "\t");
                System.out.print(rs.getInt("sem") + "\t");
                System.out.print(rs.getString("dept") + "\t");
                System.out.println(rs.getFloat("cgpi"));
            }
        } catch (SQLException s) {
            s.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
