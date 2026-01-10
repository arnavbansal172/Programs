(: books-query.xq :)
declare namespace lib = "http://example.com/books";

for $book in doc("books.xml")//lib:book
return
  <book>
      <title>{data($book/lib:title)}</title>
      <author>{data($book/lib:author)}</author>
      <year>{data($book/lib:year)}</year>
  </book>
