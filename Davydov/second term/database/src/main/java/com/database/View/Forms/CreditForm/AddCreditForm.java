package com.database.View.Forms.CreditForm;

import com.database.Controller.ClientsControllerInterface;
import com.database.Controller.CreditsControllerInterface;
import com.database.Model.ClientRecord;
import com.database.Model.CreditRecord;
import com.database.Model.Files.Writing;
import com.database.View.MyUI;
import com.vaadin.ui.Button;

import java.sql.Date;
import java.time.LocalDate;

/**
 * Created by Дмитрий on 01.04.2017.
 */
public class AddCreditForm extends CreditFormShablon
{
    private Button addCreditButton = new Button("Add Credit");
    private AddCreditForm addCreditForm = this;

    public AddCreditForm(ClientsControllerInterface clientsController,
                         CreditsControllerInterface creditsController,
                         MyUI myUI)
    {
        super();

        this.buttonHorizontalLayout.addComponent(addCreditButton);

        addCreditButton.addClickListener(new Button.ClickListener() {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                CreditRecord creditRecord = new CreditRecord();

                creditRecord.setId(Long.valueOf(clientRecord.getId()));
                creditRecord.setSum(Double.valueOf(getSum()));
                creditRecord.setPercent(Double.valueOf(getPercent()));
                creditRecord.setPaidUpSum(Double.valueOf(getPaidUpSum()));
                creditRecord.setPaidSum(Double.valueOf(getPaidSum()));
                creditRecord.setDate(Date.valueOf(getDate()));

                creditsController.saveNewCredit(creditRecord);
                ClientRecord ptr = clientsController.getByID(clientRecord.getId());
                clientsController.getByID(clientRecord.getId()).setDebtStatus(
                        creditsController.getAllCredits());

                if (creditRecord.getStatus() < ptr.getDebtStatus())
                {
                    ptr.setDebtStatus(creditRecord.getStatus());
                    clientsController.deleteClient(ptr.getId());
                    clientsController.saveNewClient(ptr);
                    myUI.upgradeClientsGrid();
                }
                addCreditForm.setVisible(false);

                writing.writeCredits(creditsController.getAllCredits());
            }
        });
    }

    public void addCreditRecord(ClientRecord clientRecord)
    {
        this.clientRecord = clientRecord;
        cleanFields();
    }

    public void cleanFields()
    {
        this.date.clear();
        this.sum.clear();
        this.paidSum.clear();
        this.paidUpSum.clear();
        this.percent.clear();
    }
}
