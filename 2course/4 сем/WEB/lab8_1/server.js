const express = require('express');
const path = require('path');

const app = express();
app.use(express.static('./dist'));
const PORT = process.env.PORT || 3000;

// Маршрут для отдачи страницы index.html
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});

// Маршрут для скачивания файла botanical_info.json
app.get('/botanical_info.json', (req, res) => {
    res.download(path.join(__dirname, 'botanical_info.json'));
});

// Запуск сервера на указанном порту
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});
