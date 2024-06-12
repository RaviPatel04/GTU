<%
Cookie nameCookie = new Cookie("UserName", request.getParameter("UserName"));
Cookie cityCookie = new Cookie("City", request.getParameter("City"));
nameCookie.setMaxAge(60 * 60 * 24); // 1 day
cityCookie.setMaxAge(60 * 60 * 24); // 1 day
response.addCookie(nameCookie);
response.addCookie(cityCookie);
%>
<body style="background-color: powderblue;">
    <a href="readCookie.jsp">Read Cookies</a>
</body>
