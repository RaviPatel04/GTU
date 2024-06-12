<html>
<head>
    <title>Reading Cookies</title>
</head>
<body style="background-color: powderblue;">
    <center>
        <h1>Reading Cookies</h1>
    </center>
    <%
    Cookie cookie = null;
    Cookie[] cookies = request.getCookies();
    if (cookies != null) {
        out.println("<h2>Found Cookies Name and Value</h2>");
        for (int i = 0; i < cookies.length; i++) {
            cookie = cookies[i];
            out.print("Name: " + cookie.getName() + ", ");
            out.print("Value: " + cookie.getValue() + " <br />");
        }
    } else {
        out.println("<h2>No cookies found</h2>");
    }
    %>
    <form action="deleteCookie.jsp">
        <button type="submit">Delete Cookies</button>
    </form>
</body>
</html>
