package com.database.View.Forms.CreditForm;

import com.database.Model.ClientRecord;
import com.database.Model.CreditRecord;
import com.database.Model.Files.Writing;
import com.vaadin.ui.*;

import java.time.LocalDate;

/**
 * Created by Дмитрий on 31.03.2017.
 */
public abstract class CreditFormShablon extends VerticalLayout
{
    protected HorizontalLayout buttonHorizontalLayout = new HorizontalLayout();
    protected ClientRecord clientRecord;

    protected TextField id = new TextField("Id");
    protected TextField sum = new TextField("All sum");
    protected TextField percent = new TextField("Percent");
    protected TextField paidUpSum = new TextField("Paid up sum");
    protected TextField paidSum = new TextField("Paid sum");
    protected DateField date = new DateField("Date");

    protected Button close = new Button("Close");

    protected Writing writing;

    private CreditFormShablon creditFormShablon;

    public CreditFormShablon()
    {
        setVisible(false);
        creditFormShablon = this;

        close.addClickListener(new Button.ClickListener() {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                creditFormShablon.setVisible(false);
            }
        });

        buttonHorizontalLayout.addComponents(close);

        this.addComponents(sum, percent, paidUpSum, paidSum, date,
                buttonHorizontalLayout);
    }

    public void setId(String id) {this.id.setValue(id);}
    public void setSum(String sum) {this.sum.setValue(sum);}
    public void setPercent(String family) {this.percent.setValue(family);}
    public void setPaidUpSum(String patronymic) {this.paidUpSum.
            setValue(patronymic);}
    public void setPaidSum(String phone) {this.paidSum.setValue(phone);}
    public void setDate(String date)
    {
        this.date.setValue(LocalDate.of(Integer.parseInt(
                date.substring(0, 4)), Integer.parseInt(date.substring(5, 7)),
                Integer.parseInt(date.substring(8, 10))));
    }
    public void setCreditRecordField(CreditRecord creditRecord)
    {
        this.setId(String.valueOf(creditRecord.getId()));
        this.setSum(String.valueOf(creditRecord.getSum()));
        this.setPercent(String.valueOf(creditRecord.getPercent()));
        this.setPaidSum(String.valueOf(creditRecord.getPaidSum()));
        this.setPaidUpSum(String.valueOf(creditRecord.getPaidUpSum()));
        this.setDate(String.valueOf(creditRecord.getDate()));
    }

    public String getId() {return this.id.getValue();}
    public String getSum() {return this.sum.getValue();}
    public String getPercent() {return this.percent.getValue();}
    public String getPaidUpSum() {return this.paidUpSum.getValue();}
    public String getPaidSum() {return this.paidSum.getValue();}
    public String getDate() {return this.date.getValue().toString();}
}
