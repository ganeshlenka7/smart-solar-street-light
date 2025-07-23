# 🌞 smart-solar-street-light

Hey! I made a simple Arduino-based project that combines **solar tracking** and a **smart street light system**. It’s fully powered by solar energy! 🔋

---

## 🔄 1. Solar Panel Tracking

- Used **2 LDR sensors** to detect sunlight direction.
- A **12V DC motor** rotates the panel to face the brighter side.
- This helps the panel get **maximum sunlight** throughout the day.

---

## 💡 2. Smart Street Light

- When it gets **dark** (LDR detects low light),  
- The **PIR sensor** checks for motion.
- If motion is detected, the **relay turns ON the light**.
- After a few seconds, the light turns OFF and keeps checking again.

---

## ⚙️ Components Used

- 2x Arduino UNO (one for solar, one for lights)  
- LDR sensors  
- PIR motion sensor  
- Relay module  
- 12V DC motor  
- Solar panel + solar converter  
- Battery  
- Light (12volt bulb/LED)  

---

## 🔋 Power Source

The **entire setup runs using solar power**.  
The **solar converter** charges a battery that powers both Arduino circuits, the motor, and the lights.

---

This project is great for saving energy using **automation + solar power**.  
Check out the code and feel free to try or modify it! 😊

---

📂 **GitHub Code Folder Includes:**
- Arduino code for Solar Tracker  
- Arduino code for Street Light System  


