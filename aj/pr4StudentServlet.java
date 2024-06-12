//this java web servlet
// Java Web > Web Application

// Right-click on the Source Packages folder.
// Select New > Servlet.

// CREATE TABLE studentinfo (
//     enrollment INT PRIMARY KEY,
//     student_name VARCHAR(50),
//     branch VARCHAR(50),
//     year VARCHAR(10)
// );



import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "StudentServlet", urlPatterns = { "/StudentServlet" })
public class pr4StudentServlet extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        // Retrieve form data
        String eno = request.getParameter("eno");
        String sname = request.getParameter("sname");
        String branch = request.getParameter("branch");
        String year = request.getParameter("year");

        // JDBC Connection details
        String url = "jdbc:mysql://localhost:3306/pr4";
        String user = "root";
        String password = "";
        try {
            // Load the MySQL JDBC driver
            Class.forName("com.mysql.jdbc.Driver");
            // Establish connection
            Connection conn = DriverManager.getConnection(url, user, password);
            // Prepare SQL statement
            String sql = "INSERT INTO studentinfo (enrollment, student_name, branch, year) VALUES (?, ?, ?, ?)";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, eno);
            pstmt.setString(2, sname);
            pstmt.setString(3, branch);
            pstmt.setString(4, year);
            // Execute the statement
            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                out.println("<h2>Student record inserted successfully!!!</h2>");
            } else {
                out.println("<h2>Error adding student record</h2>");
            }
            pstmt.close();
            conn.close();
        } catch (ClassNotFoundException | SQLException e) {
            out.println("<h2>Error: " + e.getMessage() + "</h2>");
        }
    }
}
