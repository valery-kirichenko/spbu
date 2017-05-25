package com.database.View.Forms.CreditForm;

import com.database.Controller.CreditsControllerInterface;
import com.database.Model.CreditRecord;
import com.database.Model.Files.Writing;
import com.database.View.MyUI;
import com.vaadin.ui.Button;

import java.sql.Date;

/**
 * Created by Дмитрий on 07.04.2017.
 */
public class ChangeCreditForm extends CreditFormShablon
{
    private Button saveButton = new Button("Save");
    private ChangeCreditForm changeCreditForm = this;
    CreditRecord creditRecord;

    public ChangeCreditForm(CreditsControllerInterface creditsController,
                            MyUI myUI)
    {
        super();

        saveButton.addClickListener(new Button.ClickListener()
        {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                creditsController.deleteCredit(creditRecord);

                creditRecord = new CreditRecord();
                creditRecord.setId(Long.valueOf(changeCreditForm.getId()));
                creditRecord.setSum(Double.valueOf(changeCreditForm.getSum()));
                creditRecord.setPercent(Double.valueOf(changeCreditForm.getPercent()));
                creditRecord.setPaidUpSum(Double.valueOf(changeCreditForm.getPaidUpSum()));
                creditRecord.setPaidSum(Double.valueOf(changeCreditForm.getPaidSum()));
                creditRecord.setDate(Date.valueOf(changeCreditForm.getDate()));

                creditsController.saveNewCredit(creditRecord);

                changeCreditForm.setVisible(false);
                myUI.upgradeCreditsGrid(creditRecord.getId());
                writing.writeCredits(creditsController.getAllCredits());
            }
        });

        this.buttonHorizontalLayout.addComponent(saveButton);
    }

    public void setCreditRecord(CreditRecord creditRecord)
    {
        this.creditRecord = creditRecord;
        setCreditRecordField(creditRecord);
    }
}
