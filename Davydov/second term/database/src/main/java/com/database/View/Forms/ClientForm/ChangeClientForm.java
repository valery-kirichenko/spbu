package com.database.View.Forms.ClientForm;

import com.database.Controller.ClientsControllerInterface;
import com.database.Controller.CreditsControllerInterface;
import com.database.Model.Files.Writing;
import com.database.View.Forms.CreditForm.AddCreditForm;
import com.database.View.MyUI;
import com.database.Model.ClientRecord;
import com.vaadin.ui.Button;

/**
 * Created by Дмитрий on 12.05.2017.
 */

public class ChangeClientForm extends ClientFormShablon
{
    private ClientRecord clientRecord;
    private AddCreditForm addCreditForm;
    private ChangeClientForm changeClientForm = this;

    private Button saveChangesButton = new Button("Save");

    public ChangeClientForm(AddCreditForm addCreditForm,
                            CreditsControllerInterface creditsController,
                            ClientsControllerInterface clientsController, MyUI myUI)
    {
        super();
        this.addCreditForm = addCreditForm;
        Button addCreditButton = new Button("Add credit");
        addCreditButton.addClickListener(new Button.ClickListener()
        {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                if (!addCreditForm.isVisible())
                {
                    addCreditForm.setVisible(true);
                    addCreditForm.addCreditRecord(clientRecord);
                    addCreditForm.cleanFields();
                }
                else addCreditForm.setVisible(false);
            }
        });

        saveChangesButton.addClickListener(new Button.ClickListener()
        {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                clientsController.deleteClient(clientRecord.getId());
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
                clientRecord.setDebtStatus(creditsController.getAllCredits());

                clientsController.saveNewClient(clientRecord);
                myUI.upgradeClientsGrid();

                writing.writeClients(clientsController.getAllClients());

                if (addCreditForm.isVisible())
                {
                    addCreditForm.setVisible(false);
                }

                changeClientForm.setVisible(false);
            }
        });

        this.buttonHorizontalLayout.addComponents(saveChangesButton,
                addCreditButton);
    }

    public void setFields(ClientRecord clientRecord)
    {
        this.setId(String.valueOf(clientRecord.getId()));
        this.setName(clientRecord.getName());
        this.setFamily(clientRecord.getFamily());
        this.setPatronymic(clientRecord.getPatronymic());
        this.setPhone(clientRecord.getPhone());
        this.setPassport(clientRecord.getPassport());
        this.setDate(clientRecord.getDate());
        this.setOldPassport(clientRecord.getOldPassport());
    }

    public void setClientRecord(ClientRecord clientRecord)
    {
        this.clientRecord = clientRecord;
        setFields(clientRecord);
    }
}
