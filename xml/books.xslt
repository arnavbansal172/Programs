<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:lib="http://example.com/books">
    <xsl:template match="/">
        <html>
            <head>
                <title>Book Library</title>
            </head>
            <body>
                <h1>Book Library</h1>
                <table border="1">
                    <tr>
                        <th>Title</th>
                        <th>Author</th>
                        <th>Year</th>
                    </tr>
                    <xsl:for-each select="lib:library/lib:book">
                        <tr>
                            <td><xsl:value-of select="lib:title"/></td>
                            <td><xsl:value-of select="lib:author"/></td>
                            <td><xsl:value-of select="lib:year"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>
