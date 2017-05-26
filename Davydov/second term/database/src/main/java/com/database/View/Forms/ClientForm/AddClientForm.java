package com.database.View.Forms.ClientForm;

import com.database.Controller.ClientsController;
import com.database.Controller.ClientsControllerInterface;
import com.database.Model.Files.Writing;
import com.database.View.MyUI;
import com.database.Model.ClientRecord;
import com.vaadin.ui.Button;

import java.util.Collection;

/**
 * Created by Дмитрий on 31.03.2017.
 */
public class AddClientForm extends ClientFormShablon
{
    private ClientRecord clientRecord;
    private AddClientForm addClientForm;

    private Button addButton  = new Button("Add client");

    public AddClientForm(ClientsControllerInterface clientsController, MyUI myUI)
    {
        super();
        addClientForm = this;

        addButton.addClickListener(new Button.ClickListener()
        {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                clientRecord = new ClientRecord();

                clientRecord.setId(Long.valueOf(getId()));
                clientRecord.setName(getName());
                clientRecord.setFamily(getFamily());
                clientRecord.setPatronymic(getPatronymic());
                clientRecord.setPhone(getPhone());
                clientRecord.setPassport(getPassport());
                clientRecord.setDate(getDate());
                if (getOldPassport().isEmpty()) clientRecord.setOldPassport("no information");
                else clientRecord.setOldPassport(getOldPassport());
                clientRecord.setDebtStatus(2);

                clientsController.saveNewClient(clientRecord);
                myUI.upgradeClientsGrid();

                writing.writeClients(clientsController.getAllClients());

                addClientForm.setVisible(false);
            }
        });

        close.setCaption("Close");
        close.addClickListener(new Button.ClickListener() {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent) {
                addClientForm.setVisible(false);
            }
        });

        this.buttonHorizontalLayout.addComponent(addButton);

        addAttachListener(new AttachListener() {
            @Override
            public void attach(AttachEvent attachEvent)
            {
                cleanFields();
            }
        });
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
