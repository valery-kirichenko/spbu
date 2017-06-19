package com.database.View.Forms.ClientForm;

import com.database.Model.Files.Writing;
import com.vaadin.ui.*;

import java.time.LocalDate;

/**
 * Created by Дмитрий on 31.03.2017.
 */
public abstract class ClientFormShablon extends VerticalLayout
{
    protected HorizontalLayout buttonHorizontalLayout;

    protected TextField id = new TextField("Id");
    protected TextField name = new TextField("Name");
    protected TextField family = new TextField("Family");
    protected TextField patronymic = new TextField("Patronymic");
    protected TextField phone = new TextField("Phone");
    protected TextField passport = new TextField("Passport");
    protected DateField date = new DateField("Date");
    protected TextField oldPassport = new TextField("OldPassport");

    protected Button close = new Button("Close");

    protected Writing writing;

    private ClientFormShablon clientFormShablon = this;

    public ClientFormShablon()
    {
        setVisible(false);
        buttonHorizontalLayout = new HorizontalLayout();

        addComponent(id);
        addComponents(name);
        addComponent(family);
        addComponent(patronymic);
        addComponent(phone);
        addComponent(passport);
        addComponent(date);
        addComponent(oldPassport);

        buttonHorizontalLayout.addComponents(close);

        close.addClickListener(new Button.ClickListener()
        {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                clientFormShablon.setVisible(false);
            }
        });

        this.addComponents(id, name, family, patronymic, phone,
                passport, date, oldPassport, buttonHorizontalLayout);
    }

    public void setId(String id) {this.id.setValue(id);}
    public void setName(String name) {this.name.setValue(name);}
    public void setFamily(String family) {this.family.setValue(family);}
    public void setPatronymic(String patronymic) {this.patronymic.
            setValue(patronymic);}
    public void setPhone(String phone) {this.phone.setValue(phone);}
    public void setPassport(String passport) {this.passport.setValue(
            passport);}
    public void setDate(String date)
    {
        this.date.setValue(LocalDate.of(Integer.parseInt(
        date.substring(0, 4)), Integer.parseInt(date.substring(5, 7)),
        Integer.parseInt(date.substring(8, 10))));
    }
    public void setOldPassport(String oldPassport) {this.oldPassport.
            setValue(oldPassport);}

    public String getId() {return this.id.getValue();}
    public String getName() {return this.name.getValue();}
    public String getFamily() {return this.family.getValue();}
    public String getPatronymic() {return this.patronymic.getValue();}
    public String getPhone() {return this.phone.getValue();}
    public String getPassport() {return this.passport.getValue();}
    public String getDate() {return this.date.getValue().toString();}
    public String getOldPassport() {return this.oldPassport.getValue();}
}
