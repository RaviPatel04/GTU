<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>pr6</title>
</head>
<body>
    <p>Welcome!!</p>
    <%
    out.println("Username:" +request.getParameter("name"));
    out.println("city:"+request.getParameter("city"));
    %>
    
</body>
</html>
