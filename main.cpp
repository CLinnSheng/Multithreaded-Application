/*
A weather application that a user can ask for the temperature for a particular city instantaneously while 
the program is running at the back to get the data and keep updating in cache through an API.
At here we dont use API, we'll just create some dummy value for it
*/
#include <bits/stdc++.h>
#include <thread>

void UpdateForecast(std::unordered_map<std::string, int> forecastMap) {
    
    while (true) {
        // Since we not using API to get data we will just manually stimulate the change in temperature
        for (auto& [city, temp] : forecastMap) {
            temp++;
            std::cout << city << " - " << temp << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {

    std::unordered_map<std::string, int> forecastMap = {{"Malaysia", 30}, {"Singapore", 31},
                                                        {"Indonesia", 28}};


    std::thread backGroundProgram(UpdateForecast, forecastMap);

    backGroundProgram.join();

    return 0;
}