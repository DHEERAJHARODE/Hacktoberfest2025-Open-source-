const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const expenseRoutes = require('./routes/expense');
require('dotenv').config();


const app = express();
const port = process.env.PORT || 3000;

const mongourl = process.env.MONGO_URL;

mongoose.connect(mongourl, {
  useNewUrlParser: true,
  useUnifiedTopology: true
}).then(() => console.log('Connected to MongoDB'))
  .catch(err => console.error('Could not connect to MongoDB...', err));

app.use(bodyParser.json());

app.use('/api/expenses', expenseRoutes);

app.listen(port, () => console.log(`Server running on port ${port}`));
