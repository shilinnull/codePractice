package book;

public class BookList {
    private Book[] books = new Book[10];
    private int usedSize;                 // 已经使用的个数

    public BookList() {
        this.books[0] = new Book("三国演义","罗贯中",10,"小说");
        this.books[1] = new Book("西游记","吴承恩",59,"小说");
        this.books[2] = new Book("红楼梦","曹雪芹",16,"小说");

        usedSize = 3;
    }




}
