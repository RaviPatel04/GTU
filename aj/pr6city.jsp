<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>pr 6</title>
</head>
<body>
    <p>Welcome!!</p>
    <%
    out.println("Username: " + request.getParameter("name") + "<br>");
    out.println("City: " + request.getParameter("city"));
    %>
</body>
</html>
