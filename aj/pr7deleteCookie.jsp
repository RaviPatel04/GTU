<html>
<head>
    <title>Delete Cookies</title>
</head>
<body style="background-color: powderblue;">
    <%
    Cookie cookie = null;
    Cookie[] cookies = request.getCookies();
    if (cookies != null) {
        for (int i = 0; i < cookies.length; i++) {
            cookie = cookies[i];
            cookie.setMaxAge(0);
            response.addCookie(cookie);
        }
    } else {
        out.println("<h2>No cookies found</h2>");
    }
    %>
    <h1>All the Cookies Deleted</h1>
    <a href="readCookie.jsp">Read Cookies</a>
</body>
</html>
