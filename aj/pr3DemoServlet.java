//this java web servlet
// Java Web > Web Application

// Right-click on the Source Packages folder.
// Select New > Servlet.
//CREATE TABLE empinfo (
//     EmpID INT PRIMARY KEY,
//     EmpName VARCHAR(50),
//     EmpDept VARCHAR(50),
//     EmpCity VARCHAR(50)
// );



import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "DemoServlet", urlPatterns = { "/DemoServlet" })
public class pr3DemoServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();

        try {
            Class.forName("com.mysql.jdbc.Driver").newInstance();
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/pr5", "root", "");
            Statement st = con.createStatement();
            String id = request.getParameter("eid");
            String name = request.getParameter("ename");
            String dept = request.getParameter("dept");
            String city = request.getParameter("city");
            String insert_emp = "INSERT INTO empinfo (EmpID, EmpName, EmpDept, EmpCity) VALUES (" + id + ",'" + name + "','" + dept + "','" + city + "')";
            int n = st.executeUpdate(insert_emp);

            if (n == 0) {
                out.print("<h1>Record not inserted!!!</h1>");
            } else {
                out.print("<h1>Record inserted successfully!!!</h1>");
            }
            st.close();
            con.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
