const { Client, GatewayIntentBits, Partials } = require('discord.js');

const client = new Client({
    intents: [
        GatewayIntentBits.Guilds,
        GatewayIntentBits.GuildMessages,
        GatewayIntentBits.GuildMembers,
        GatewayIntentBits.MessageContent,
    ],
    partials: [
        Partials.Channel,
        Partials.Message,
    ]
});

// Ensure to store your token securely
const token = "";

client.on('ready', () => {
    console.log(`Client has been logged into ${client.user.username}`);
});

client.on('messageCreate', (message) => {
    if(message.content.toLowerCase() === "!halo bb") {
        message.reply('Aloo!!').catch(err => console.log(err));
    }
});

client.login(token).catch(err => console.log('Failed to login:', err));
