package book;

public class Book {
    private String name;        // 书名
    private String anthor;      // 作者
    private int prise;          // 价格
    private String type;        // 书的类型
    private boolean isBorrowed; // 是否被借阅

    public Book(String name, String anthor, int prise, String type) {
        this.name = name;
        this.anthor = anthor;
        this.prise = prise;
        this.type = type;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAnthor() {
        return anthor;
    }

    public void setAnthor(String anthor) {
        this.anthor = anthor;
    }

    public int getPrise() {
        return prise;
    }

    public void setPrise(int prise) {
        this.prise = prise;
    }

    public boolean isBorrowed() {
        return isBorrowed;
    }

    public void setBorrowed(boolean borrowed) {
        isBorrowed = borrowed;
    }

    @Override
    public String toString() {
        return "Book{" +
                "name='" + name + '\'' +
                ", anthor='" + anthor + '\'' +
                ", prise=" + prise +
                ( (isBorrowed) ? " 已借出" : " 未借出" ) +
                '}';
    }
}
