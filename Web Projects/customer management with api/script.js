console.log("hello")

const authUrl = "https://qa2.sunbasedata.com/sunbase/portal/api/assignment_auth.jsp";
const createCustomerUrl = "https://qa2.sunbasedata.com/sunbase/portal/api/assignment.jsp";
let authToken = "";  // Variable to store the Bearer token



async function login() {
  const loginId = document.getElementById("loginId").value;
  const password = document.getElementById("password").value;

  try {
      const response = await fetch(authUrl, {
          method: "POST",
          headers: {
              "Content-Type": "application/json"
          },
          body: JSON.stringify({ login_id: loginId, password: password })
      });

      const data = await response.json();

      if (response.ok) {
          authToken = data.token;
          showCustomerListScreen();
      } else {
          displayResponse(response.status, data);
      }
  } catch (error) {
      console.error("Error during login:", error);
  }
}





async function authenticateUser() {

  console.log("authenticateuser")
    const loginData = {
        login_id: "test@sunbasedata.com",
        password: "Test@123"
    };

    try {
        const response = await fetch(authUrl, {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(loginData)
        });

        const data = await response.json();

        // Store the Bearer token for later use
        authToken = data.token;

        displayResponse(response.status, data);
    } catch (error) {
        console.error("Error during authentication:", error);
    }
}



async function createCustomer() {
    try {
        // Check if the authToken is empty (user not authenticated)
        if (!authToken) {
            console.error("User not authenticated. Please authenticate first.");
            return;
        }

        const customerData = {
            "first_name": "Jane",
            "last_name": "Doe",
            "street": "Elvnu Street",
            "address": "H no 2 ",
            "city": "Delhi",
            "state": "Delhi",
            "email": "sam@gmail.com",
            "phone": "12345678"
            }
            

        const response = await fetch(createCustomerUrl, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${authToken}`
            },
            body: JSON.stringify(customerData)
        });

        const data = await response.json();
        displayResponse(response.status, data);
    } catch (error) {
        console.error("Error during customer creation:", error);
    }
}

// Update the getCustomerList function to populate the table
async function getCustomerList() {
  try {
      // ... existing code ...

      const response = await fetch(customerListUrl, {
          method: "GET",
          headers: {
              "Authorization": `Bearer ${authToken}`
          }
      });

      const data = await response.json();

      // Clear existing table rows
      const tableBody = document.getElementById("customerTableBody");
      tableBody.innerHTML = "";

      // Populate the table with customer data
      data.forEach(customer => {
          const row = document.createElement("tr");
          row.innerHTML = `
              <td>${customer.first_name}</td>
              <td>${customer.last_name}</td>
              <td>${customer.email}</td>
              <td>${customer.phone}</td>
              <td class="actionButtons">
                  <span class="editButton" onclick="editCustomer('${customer.uuid}')">Edit</span>
                  <span class="deleteButton" onclick="deleteCustomer('${customer.uuid}')">Delete</span>
              </td>
          `;
          tableBody.appendChild(row);
      });

      displayResponse(response.status, data);
  } catch (error) {
      console.error("Error while getting customer list:", error);
  }
}




//delete customer

async function deleteCustomer() {
  try {
      if (!authToken) {
          console.error("User not authenticated. Please authenticate first.");
          return;
      }

      const customerUuid = prompt("Enter the UUID of the customer to delete:");

      if (!customerUuid) {
          console.error("UUID not provided. Please enter a valid UUID.");
          return;
      }

      const deleteCustomerUrl = "https://qa2.sunbasedata.com/sunbase/portal/api/assignment.jsp";
      const deleteCustomerData = {
          cmd: "delete",
          uuid: customerUuid
      };

      const response = await fetch(deleteCustomerUrl, {
          method: "POST",
          headers: {
              "Content-Type": "application/json",
              "Authorization": `Bearer ${authToken}`
          },
          body: JSON.stringify(deleteCustomerData)
      });

      const data = await response.json();
      displayResponse(response.status, data);
  } catch (error) {
      console.error("Error during customer deletion:", error);
  }
}



async function updateCustomer() {
  try {
      if (!authToken) {
          console.error("User not authenticated. Please authenticate first.");
          return;
      }

      const customerUuid = prompt("Enter the UUID of the customer to update:");

      if (!customerUuid) {
          console.error("UUID not provided. Please enter a valid UUID.");
          return;
      }

      const updateCustomerUrl = "https://qa2.sunbasedata.com/sunbase/portal/api/assignment.jsp";
      const updateCustomerData = {
          cmd: "update",
          uuid: customerUuid,
          first_name: "Jane",
          last_name: "Doe",
          street: "Elvnu Street",
          address: "H no 2",
          city: "Delhi",
          state: "Delhi",
          email: "sam@gmail.com",
          phone: "12345678"
      };

      const response = await fetch(updateCustomerUrl, {
          method: "POST",
          headers: {
              "Content-Type": "application/json",
              "Authorization": `Bearer ${authToken}`
          },
          body: JSON.stringify(updateCustomerData)
      });

      const data = await response.json();
      displayResponse(response.status, data);
  } catch (error) {
      console.error("Error during customer update:", error);
  }
}
