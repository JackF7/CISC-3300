 // Question 4
 
 // Make a get request to retrieve data
 $.ajax({
    url: 'http://localhost:3000/posts',
    type: 'GET',
    success: function(data) {
    
    console.log('The GET request was successful:', data);
        
  },
});

// Make a POST request to add a new resource
$.ajax({
    url: 'http://localhost:3000/posts',
    type: 'POST',
    contentType: 'application/json',
    data: JSON.stringify({id: '3', title: 'a third title', views: '300' }),
    success: function(data) {

    const postLogMessage = `The POST request was successful: id: ${data.id}, title: ${data.title}, views: ${data.views}`;

    console.log(postLogMessage);
    },
});

// Make a put request to replace a previous resource
const postIdToUpdate = 1;
$.ajax({
    url: `http://localhost:3000/posts/3`,
    type: 'PUT',
    contentType: 'application/json',
    data: JSON.stringify({title: 'a fourth title (but really the third)', views: '400' }),
    success: function(data) {

        const putLogMessage = `The PUT request was successful: id: ${data.id}, title: ${data.title}, views: ${data.views}`;
    
        console.log(putLogMessage);
    }  
});

// Question 5

// API URL for Open-Meteo (New York City coordinates)
const weatherAPIUrl = 'https://api.open-meteo.com/v1/forecast?latitude=40.7128&longitude=-74.0060&current=temperature_2m,wind_speed_10m&hourly=temperature_2m,relative_humidity_2m,wind_speed_10m';
        
// Make a GET request to the Open-Meteo API
$.ajax({
    url: weatherAPIUrl,
    type: 'GET',
    success: function(data) {
        console.log(data);
        // Convert from Celsius to Fahrenheit
        const tempCelsius = data.current.temperature_2m;
        const tempFahrenheit = (tempCelsius * 9/5) + 32;

        // Convert from km/h to mph
        const windSpeedInMiles = data.current.wind_speed_10m * 0.621371;

        // Update HTML elements with data from the API response
        $('#location').text(`Coordinates: ${data.latitude} , ${data.longitude}`);
        $('#temperature').text(`Temperature: ${tempFahrenheit.toFixed(2)} °F`);
        $('#windSpeed').text(`Wind Speed: ${windSpeedInMiles.toFixed(2)} mph`);
    },
    error: function(error) {
        console.error('API request failed:', error);
        // Display an error message if the API request fails
        $('#weather').html('Failed to fetch weather data.');
    }
});