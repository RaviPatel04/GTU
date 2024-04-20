import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "NewServlet", urlPatterns = { "/NewServlet" })
public class NewServlet extends HttpServlet {
    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        // Retrieve form data
        String en = request.getParameter("ENROLMENT");
        String sname = request.getParameter("STUDENT_NAME");
        String branch = request.getParameter("BRANCH");
        String yr = request.getParameter("YEAR");
        // JDBC Connection details
        String url = "jdbc:mysql://localhost:3306/pr4";
        String user = "root";
        String password = "";
        try {
            try {
                // Load the MySQL JDBC driver
                Class.forName("com.mysql.jdbc.Driver");
            } catch (ClassNotFoundException e) {
                out.println("<h2>Error: " + e.getMessage() + "</h2>");
            }
            // Establish connection
            Connection conn = DriverManager.getConnection(url, user, password);
            // Prepare SQL statement
            String sql = "INSERT INTO studentinfo (enrollment, student_name, branch, year) VALUES (?, ?, ?, ?)";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, en);
            pstmt.setString(2, sname);
            pstmt.setString(3, branch);
            pstmt.setString(4, yr);
            // Execute the statement
            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                out.println("<h2>Student record inserted successfully!!!</h2>");
            } else {
                out.println("<h2>Error adding employee</h2>");
            }
            // Close resources
            pstmt.close();
            conn.close();
        } catch (SQLException e) {
            out.println("<h2>Error: " + e.getMessage() + "</h2>");
        }
    }
}
