<!-- Right-click on the Web Pages folder in the Projects pane.
Select New > JSP. -->

<html>
<head>
    <title>Practical-3 jsp</title>
    <style>
        table td {
            padding: 8px;
        }
    </style>
</head>
<body style="font-family: 'Alata';">
    <form action="DemoServlet" method="POST">
        <table border="1" style="width: 360px;">
            <tr>
                <td>Employee ID:</td>
                <td><input type="text" name="eid"></td>
            </tr>
            <tr>
                <td>Employee Name:</td>
                <td><input type="text" name="ename"></td>
            </tr>
            <tr>
                <td>Department:</td>
                <td><input type="text" name="dept"></td>
            </tr>
            <tr>
                <td>City:</td>
                <td><input type="text" name="city"></td>
            </tr>
            <tr>
                <td colspan="2" align="center"><input style="width: 50%; border-radius: 10px;" type="submit" value="Submit"></td>
            </tr>
        </table>
    </form>
</body>
</html>
