package com.database.View;

import javax.servlet.annotation.WebServlet;

import com.database.Controller.ClientsControllerInterface;
import com.database.Controller.CreditsControllerInterface;
import com.database.Model.Files.Writing;
import com.database.View.Forms.ClientForm.AddClientForm;
import com.database.View.Forms.ClientForm.ChangeClientForm;
import com.database.View.Forms.CreditForm.AddCreditForm;
import com.database.View.Forms.CreditForm.ChangeCreditForm;
import com.database.View.Forms.SearchForm.SearchForm;
import com.database.Model.BankHelper;
import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.database.Model.ClientRecord;
import com.database.Model.CreditRecord;
import com.vaadin.server.FontAwesome;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import com.vaadin.ui.Button;
import com.vaadin.ui.TextField;
import com.vaadin.ui.components.grid.ItemClickListener;
import com.vaadin.ui.themes.ValoTheme;
import org.springframework.beans.factory.annotation.Autowired;

/**
 * This UI is the application entry point. A UI may either represent a browser window 
 * (or tab) or some part of a html page where a Vaadin application is embedded.
 * <p>
 * The UI is initialized using {@link #init(VaadinRequest)}. This method is intended to be 
 * overridden to add component to the user interface and initialize non-component functionality.
 */

@SpringUI
@Theme("mytheme")
public class MyUI extends UI
{
    @Autowired
    private ClientsControllerInterface clientsController;

    @Autowired
    private CreditsControllerInterface creditsController;

    private SearchForm searchForm;
    private AddCreditForm addCreditForm;
    private AddClientForm addClientForm;
    private ChangeClientForm changeClientForm;
    private ChangeCreditForm changeCreditForm;

    private Grid<ClientRecord> clientsGrid;
    private Grid<CreditRecord> creditsGrid;

    @Override
    protected void init(VaadinRequest vaadinRequest)
    {
        final VerticalLayout verticalLayout = new VerticalLayout();
        final HorizontalLayout horizontalLayout = new HorizontalLayout();
        final HorizontalLayout buttonHorizontalLayout = new HorizontalLayout();

        clientsGrid = new Grid();
        clientsGrid.setItems(clientsController.getAllClients());
        clientGridInitialization(clientsGrid);

        creditsGrid = new Grid<>();
        creditsGrid.setItems(creditsController.getAllCredits());
        creditGridInitialization(creditsGrid);

        searchForm = new SearchForm(clientsGrid, clientsController);
        addCreditForm = new AddCreditForm(clientsController, creditsController, this);
        addClientForm = new AddClientForm(clientsController, this);
        changeClientForm = new ChangeClientForm(addCreditForm, creditsController,
                clientsController, this);
        changeCreditForm = new ChangeCreditForm(creditsController, this);

        BankHelper bankHelper = new BankHelper();

        TextField filterText = new TextField("Search");
        filterText.addValueChangeListener(e ->
        {
            clientsGrid.setItems(bankHelper.getClientsByString(
                    clientsController.getAllClients(),
                    filterText.getValue()));
        });
        Button clearFilterTextBtn = new Button(FontAwesome.TIMES);

        clearFilterTextBtn.setDescription("Clear the current filter");
        clearFilterTextBtn.addClickListener(e -> filterText.clear());

        CssLayout filtering = new CssLayout();
        filtering.addComponents(filterText, clearFilterTextBtn);
        filtering.setStyleName(ValoTheme.LAYOUT_COMPONENT_GROUP);

        clientsGrid.addItemClickListener(new ItemClickListener<ClientRecord>()
        {
            @Override
            public void itemClick(Grid.ItemClick<ClientRecord> itemClick)
            {
                changeClientForm.setVisible(true);

                changeClientForm.setClientRecord(itemClick.getItem());

                creditsGrid.setItems(clientsController.getByID
                        (itemClick.getItem().getId()).getCredits());

                if (addClientForm.isVisible()) {addClientForm.setVisible(false);}
                if (changeCreditForm.isVisible()) {changeCreditForm.setVisible(false);}
                if (searchForm.isVisible()) searchForm.setVisible(false);
            }
        });

        creditsGrid.addItemClickListener(new ItemClickListener<CreditRecord>()
        {
            @Override
            public void itemClick(Grid.ItemClick<CreditRecord> itemClick)
            {
                changeCreditForm.setCreditRecord(itemClick.getItem());

                if (changeClientForm.isVisible()) {changeClientForm.setVisible(false);}
                if (addClientForm.isVisible()) {addClientForm.setVisible(false);}
                if (addCreditForm.isVisible()) {addCreditForm.setVisible(false);}
                if (searchForm.isVisible()) searchForm.setVisible(false);

                changeCreditForm.setVisible(true);
            }
        });

        Button addClientButton = new Button("Add client");
        addClientButton.addClickListener(new Button.ClickListener()
        {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                if (!addClientForm.isVisible())
                {
                    addClientForm.setVisible(true);
                    addClientForm.cleanFields();
                }
                else addClientForm.setVisible(false);

                if (changeClientForm.isVisible()) {changeClientForm.setVisible(false);}
                if (changeCreditForm.isVisible()) {changeCreditForm.setVisible(false);}
                if (addCreditForm.isVisible()) {addCreditForm.setVisible(false);}
                if (searchForm.isVisible()) searchForm.setVisible(false);
            }
        });

        Button searchClientButton = new Button("Global search");
        searchClientButton.addClickListener(new Button.ClickListener() {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent)
            {
                if (changeClientForm.isVisible()) {changeClientForm.setVisible(false);}
                if (changeCreditForm.isVisible()) {changeCreditForm.setVisible(false);}
                if (addClientForm.isVisible()) {addClientForm.setVisible(false);}
                if (addCreditForm.isVisible()) {addCreditForm.setVisible(false);}
                if (searchForm.isVisible()) searchForm.setVisible(false);
                else searchForm.setVisible(true);
            }
        });

        buttonHorizontalLayout.addComponents(addClientButton, searchClientButton);
        horizontalLayout.addComponents(clientsGrid, creditsGrid);
        verticalLayout.addComponents(buttonHorizontalLayout,
                filtering, horizontalLayout, changeClientForm,
                changeCreditForm, addClientForm, addCreditForm,
                searchForm);

        setContent(verticalLayout);
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {}

    private void clientGridInitialization(Grid <ClientRecord> clientsGrid)
    {
        clientsGrid.setCaption("Clients");
        clientsGrid.addColumn(ClientRecord::getDebtStatusWord).setCaption("Status");
        clientsGrid.addColumn(ClientRecord::getId).setCaption("Id");
        clientsGrid.addColumn(ClientRecord::getName).setCaption("Name");
        clientsGrid.addColumn(ClientRecord::getFamily).setCaption("Family");
        clientsGrid.addColumn(ClientRecord::getPatronymic).setCaption("Patronymic");
        clientsGrid.addColumn(ClientRecord::getPhone).setCaption("Phone number");
        clientsGrid.addColumn(ClientRecord::getPassport).setCaption("Passport");
        clientsGrid.addColumn(ClientRecord::getDate).setCaption("Date");
        clientsGrid.addColumn(ClientRecord::getOldPassport).setCaption("Old passport");
        clientsGrid.getEditor().setEnabled(true);
        clientsGrid.setStyleGenerator(client -> {
            int clientDebtStatus = client.getDebtStatus();
            if (clientDebtStatus == 0) return "red";
            else if (clientDebtStatus == 1) return "yellow";
            else return "green";
        });
    }
    private void creditGridInitialization(Grid <CreditRecord> creditsGrid)
    {
        creditsGrid.setCaption("Credits");
        creditsGrid.addColumn(CreditRecord::getId).setCaption("Id");
        creditsGrid.addColumn(CreditRecord::getSum).setCaption("All sum");
        creditsGrid.addColumn(CreditRecord::getPaidUpSum).setCaption("Paid up sum");
        creditsGrid.addColumn(CreditRecord::getPaidSum).setCaption("Paid sum");
        creditsGrid.addColumn(CreditRecord::getDate).setCaption("Date");
        creditsGrid.addColumn(CreditRecord::getPercent).setCaption("Per cent");
        creditsGrid.getEditor().setEnabled(true);
        creditsGrid.setStyleGenerator(credit -> {
            int creditStatus = credit.getStatus();
            if (creditStatus == 0) return "red";
            else if (creditStatus == 1) return "yellow";
            else return "green";
        });
    }

    public void upgradeClientsGrid()
    {
        clientsGrid.setItems(clientsController.getAllClients());
    }
    public void upgradeCreditsGrid(Long id)
    {
        creditsGrid.setItems(clientsController.getByID(id).
                getCredits());
    }

}
