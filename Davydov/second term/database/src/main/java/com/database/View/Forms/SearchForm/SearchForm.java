package com.database.View.Forms.SearchForm;

import com.database.Controller.ClientsControllerInterface;
import com.database.Model.BankHelper;
import com.database.Model.ClientRecord;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;

import java.time.LocalDate;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by Дмитрий on 01.04.2017.
 */

public class SearchForm extends VerticalLayout
{
    private TextField id = new TextField("Id");
    private TextField name = new TextField("Name");
    private TextField family = new TextField("Family");
    private TextField patronymic = new TextField("Patronymic");
    private TextField phone = new TextField("Phone");
    private TextField passport = new TextField("Passport");
    private DateField date = new DateField("Date");
    private TextField oldPassport = new TextField("OldPassport");

    private BankHelper bankHelper = new BankHelper();

   public SearchForm(Grid<ClientRecord> clientsGrid,
                     ClientsControllerInterface clientsController)
    {
        setVisible(false);
        SearchForm searchForm = this;

        Button search = new Button("Search");
        search.addClickListener(new Button.ClickListener() {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                List<ClientRecord> clientsRecords = (List)
                        clientsController.getAllClients();
                ClientRecord clientRecord = new ClientRecord();

                try
                {
                    if (!id.isEmpty())
                    clientRecord.setId(Long.valueOf(id.getValue()));
                    if (!name.isEmpty())
                    clientRecord.setName(name.getValue());
                    if (!family.isEmpty())
                    clientRecord.setFamily(family.getValue());
                    if (!patronymic.isEmpty())
                    clientRecord.setPatronymic(patronymic.getValue());
                    if (!phone.isEmpty())
                    clientRecord.setPhone(phone.getValue());
                    if (!passport.isEmpty())
                    clientRecord.setPassport(passport.getValue());
                    if (!date.isEmpty())
                    clientRecord.setDate(date.getValue().toString());
                    if (!oldPassport.isEmpty())
                    clientRecord.setOldPassport(oldPassport.getValue());

                    clientsGrid.setItems(bankHelper.
                            getClientsByFields(clientsRecords, clientRecord));

                }catch (NullPointerException e) {}
                finally
                {
                    cleanFields();
                    searchForm.setVisible(false);
                }
            }
        });

        addComponents(id, name, family, patronymic, phone,
                passport, date, oldPassport, search);
    }

    public void cleanFields()
    {
        this.id.clear();
        this.name.clear();
        this.family.clear();
        this.patronymic.clear();
        this.phone.clear();
        this.passport.clear();
        this.date.clear();
        this.oldPassport.clear();
    }
}
