<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% 
String items = (String) session.getAttribute("cart_items");
out.print(items); 
%>
