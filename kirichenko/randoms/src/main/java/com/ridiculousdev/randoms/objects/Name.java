package com.ridiculousdev.randoms.objects;

/**
 * Created by valera5505 on 20.06.2017.
 */
public class Name {
    private String title, first, last;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getFirst() {
        return first;
    }

    public void setFirst(String first) {
        this.first = first;
    }

    public String getLast() {
        return last;
    }

    public void setLast(String last) {
        this.last = last;
    }

    @Override
    public String toString() {
        return first.substring(0, 1).toUpperCase() + first.substring(1) + " " +
                last.substring(0, 1).toUpperCase() + last.substring(1);
    }
}
