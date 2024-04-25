<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <title>Employee Details</title>
            </head>
            <body>
                <h2>Employee Details</h2>
                <table>
                    <tr>
                        <th>First Name</th>
                        <th>Last Name</th>
                        <th>Join Date</th>
                        <th>Birth Date</th>
                        <th>Age</th>
                        <th>Salary</th>
                    </tr>
                    <xsl:for-each select="college/employee/employeeDetails">
                        <tr>
                            <td>
                                <xsl:value-of select="fname" />
                            </td>
                            <td>
                                <xsl:value-of select="lname" />
                            </td>
                            <td>
                                <xsl:value-of select="joindate" />
                            </td>
                            <td>
                                <xsl:value-of select="bdate" />
                            </td>
                            <td>
                                <xsl:value-of select="age" />
                            </td>
                            <td>
                                <xsl:value-of select="salary" />
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>