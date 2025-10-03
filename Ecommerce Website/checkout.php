<?php
session_start();
if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit;
}

include 'database.php';

$user_id = $_SESSION['user_id'];
$total_price = 0;

// Fetch cart items from the database
$sql = "SELECT p.price, c.quantity 
        FROM carts c
        JOIN products p ON c.product_id = p.id
        WHERE c.user_id = $user_id";
$result = $conn->query($sql);

if ($result && $result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        $total_price += $row['price'] * $row['quantity'];
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Checkout</title>
    <link rel="stylesheet" href="styles.css">
    <style>
        html, body {
            margin: 0;
            padding: 0;
            min-height: 100%;
            overflow-x: hidden;
        }
        main {
            padding-bottom: 120px;
        }
        form {
            max-width: 500px;
            margin: 20px auto;
            padding: 20px;
            background: #f9f9f9;
            border-radius: 8px;
        }
        fieldset {
            border: 1px solid #ddd;
            padding: 15px;
            margin-bottom: 20px;
        }
        label {
            display: block;
            margin-top: 10px;
        }
        input[type="text"],
        input[type="number"] {
            width: 100%;
            padding: 8px;
            margin-top: 5px;
        }
        button {
            padding: 10px 20px;
            width: 100%;
            background-color: #4CAF50;
            color: white;
            border: none;
            cursor: pointer;
            margin-top: 10px;
        }
        button:hover {
            background-color: #45a049;
        }
        footer {
            position: relative;
            bottom: 0;
            width: 100%;
        }
        .total-price {
            text-align: center;
            font-weight: bold;
            font-size: 18px;
            margin-top: 10px;
        }
    </style>
</head>
<body>

<?php include 'header.php'; ?>

<main>
    <h2 style="text-align:center; margin-top:20px;">Checkout</h2>

    <form id="checkoutForm" action="place_order.php" method="POST">
        <fieldset>
            <legend><strong>Shipping Details</strong></legend>
            
            <label for="name">Full Name:</label>
            <input type="text" id="name" name="name" required>

            <label for="address">Address:</label>
            <input type="text" id="address" name="address" required>

            <label for="pin">PIN Code:</label>
            <input type="text" id="pin" name="pin" pattern="\d{6}" title="6-digit PIN code" maxlength="6" required>

            <label for="state">State:</label>
            <input type="text" id="state" name="state" required>

            <label for="country">Country:</label>
            <input type="text" id="country" name="country" required>
        </fieldset>

        <fieldset>
            <legend><strong>Payment Method</strong></legend>

            <label><input type="radio" name="payment_method" value="cod" checked> Cash on Delivery</label>
            <label><input type="radio" name="payment_method" value="card"> Credit Card</label>

            <div id="cardDetails" style="display:none;">
                <label for="card_number">Card Number:</label>
                <input type="text" id="card_number" name="card_number" pattern="\d{16}" maxlength="16" title="Enter 16-digit card number">

                <label for="expiry">Expiry Date (MM/YY):</label>
                <input type="text" id="expiry" name="expiry" pattern="\d{2}/\d{2}" maxlength="5" title="Format: MM/YY">

                <label for="cvv">CVV:</label>
                <input type="text" id="cvv" name="cvv" pattern="\d{3}" maxlength="3" title="3-digit CVV">
            </div>
        </fieldset>

        <input type="hidden" name="total_price" value="<?php echo $total_price; ?>">

        <p class="total-price">Total Price: ₹<?php echo $total_price; ?></p>

        <button type="submit">Place Order</button>
    </form>
</main>

<script>
const form = document.getElementById('checkoutForm');
const paymentRadios = document.querySelectorAll('input[name="payment_method"]');
const cardDetails = document.getElementById('cardDetails');

function toggleCardFields() {
    if (document.querySelector('input[name="payment_method"]:checked').value === 'card') {
        cardDetails.style.display = 'block';
        document.getElementById('card_number').required = true;
        document.getElementById('expiry').required = true;
        document.getElementById('cvv').required = true;
    } else {
        cardDetails.style.display = 'none';
        document.getElementById('card_number').required = false;
        document.getElementById('expiry').required = false;
        document.getElementById('cvv').required = false;
    }
}

paymentRadios.forEach(radio => {
    radio.addEventListener('change', toggleCardFields);
});
toggleCardFields();
</script>

<?php include 'footer.php'; ?>
</body>
</html>