<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Pr8</title>
    <style>
        img {
            height: 100px;
        }
    </style>
</head>
<body>
    <table border="1">
        <tr>
            <th> Sr.No </th>
            <th> Product Name</th>
            <th>Image </th>
            <th> Add to Cart</td>
        </tr>
        <tr>
            <td>1</td>
            <td>Laptop</td>
            <td> <img src="laptop.jfif"></td>
            <td><a href="shopping.jsp?item=laptop">Add To Cart</a></td>
        </tr>
        <tr>
            <td>2</td>
            <td>Smart Phone</td>
            <td> <img src="mobile.jfif"></td>
            <td><a href="shopping.jsp?item=mobile">Add To Cart</a></td>
        </tr>
        <tr>
            <td>3</td>
            <td>AC</td>
            <td> <img src="ac.jfif"></td>
            <td><a href="shopping.jsp?item=ac">Add To Cart</a></td>
        </tr>
    </table>
    <div>
        <a href="my_cart.jsp">Cart</a>
    </div>
<%
String item = request.getParameter("item");
String cart_items = (String) session.getAttribute("cart_items") != null ? (String) session.getAttribute("cart_items") : "";
if (item != null) {
    cart_items += " " + item;
    session.setAttribute("cart_items", cart_items);
}
%>
</body>
</html>
