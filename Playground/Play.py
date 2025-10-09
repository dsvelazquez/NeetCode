import tkinter as tk
from tkinter import messagebox
import datetime
import time
import threading
import os

class ClockInReminder:
    def __init__(self):
        self.reminded_today = False
        self.check_interval = 300  # Check every 5 minutes
        
    def is_work_time(self):
        """Check if it's currently work time (8am-5pm, Monday-Friday)"""
        now = datetime.datetime.now()
        
        # Check if it's a weekday (Monday = 0, Sunday = 6)
        if now.weekday() >= 5:  # Saturday or Sunday
            return False
            
        # Check if it's within work hours (8am-5pm)
        work_start = now.replace(hour=8, minute=0, second=0, microsecond=0)
        work_end = now.replace(hour=17, minute=0, second=0, microsecond=0)
        
        return work_start <= now <= work_end
    
    def is_clock_in_time(self):
        """Check if it's time to show clock-in reminder (8am-9am)"""
        now = datetime.datetime.now()
        
        if now.weekday() >= 5:  # Weekend
            return False
            
        # Show reminder between 8am-9am
        reminder_start = now.replace(hour=8, minute=0, second=0, microsecond=0)
        reminder_end = now.replace(hour=9, minute=0, second=0, microsecond=0)
        
        return reminder_start <= now <= reminder_end
    
    def show_vibrant_popup(self):
        """Show a vibrant, attention-grabbing popup"""
        root = tk.Tk()
        root.withdraw()  # Hide the main window
        
        # Configure the popup window
        popup = tk.Toplevel(root)
        popup.title("⏰ CLOCK IN REMINDER ⏰")
        popup.geometry("400x200")
        popup.configure(bg='#FF6B35')  # Vibrant orange background
        
        # Make it stay on top and grab focus
        popup.attributes('-topmost', True)
        popup.focus_force()
        popup.grab_set()
        
        # Center the window on screen
        popup.update_idletasks()
        x = (popup.winfo_screenwidth() // 2) - (popup.winfo_width() // 2)
        y = (popup.winfo_screenheight() // 2) - (popup.winfo_height() // 2)
        popup.geometry(f"+{x}+{y}")
        
        # Create vibrant content
        title_label = tk.Label(
            popup,
            text="🚨 CLOCK IN REMINDER 🚨",
            font=('Arial', 16, 'bold'),
            fg='white',
            bg='#FF6B35',
            pady=10
        )
        title_label.pack()
        
        message_label = tk.Label(
            popup,
            text="Don't forget to clock in!\nIt's time to start your workday! ⏰",
            font=('Arial', 12),
            fg='white',
            bg='#FF6B35',
            pady=10
        )
        message_label.pack()
        
        # Buttons frame
        button_frame = tk.Frame(popup, bg='#FF6B35')
        button_frame.pack(pady=20)
        
        # "I clocked in" button
        clocked_in_btn = tk.Button(
            button_frame,
            text="✅ I Clocked In!",
            font=('Arial', 10, 'bold'),
            bg='#28A745',  # Green
            fg='white',
            pady=5,
            padx=15,
            command=popup.destroy
        )
        clocked_in_btn.pack(side=tk.LEFT, padx=5)
        
        # "Remind me later" button
        remind_later_btn = tk.Button(
            button_frame,
            text="⏰ Remind in 10 min",
            font=('Arial', 10),
            bg='#FFC107',  # Yellow
            fg='black',
            pady=5,
            padx=15,
            command=lambda: self.snooze_reminder(popup)
        )
        remind_later_btn.pack(side=tk.LEFT, padx=5)
        
        # Make the window flash to get attention
        self.flash_window(popup)
        
        root.mainloop()
    
    def flash_window(self, window):
        """Make the window flash to grab attention"""
        def flash():
            for _ in range(6):  # Flash 6 times
                try:
                    window.configure(bg='#FFD700')  # Gold
                    window.update()
                    time.sleep(0.2)
                    window.configure(bg='#FF6B35')  # Orange
                    window.update()
                    time.sleep(0.2)
                except tk.TclError:
                    break  # Window was closed
        
        threading.Thread(target=flash, daemon=True).start()
    
    def snooze_reminder(self, popup):
        """Snooze reminder for 10 minutes"""
        popup.destroy()
        threading.Timer(600, self.show_vibrant_popup).start()  # 10 minutes
    
    def reset_daily_reminder(self):
        """Reset the reminder flag at midnight"""
        now = datetime.datetime.now()
        tomorrow = now.replace(hour=0, minute=0, second=0, microsecond=0) + datetime.timedelta(days=1)
        seconds_until_midnight = (tomorrow - now).total_seconds()
        
        threading.Timer(seconds_until_midnight, self.daily_reset).start()
    
    def daily_reset(self):
        """Reset reminder flag and schedule next reset"""
        self.reminded_today = False
        self.reset_daily_reminder()
    
    def run(self):
        """Main loop to check for reminder time"""
        print("Clock-in reminder is running...")
        print("Will show reminder between 8:00-9:00 AM on weekdays")
        print("Press Ctrl+C to stop")
        
        self.reset_daily_reminder()
        
        try:
            while True:
                if self.is_clock_in_time() and not self.reminded_today:
                    print(f"Showing clock-in reminder at {datetime.datetime.now().strftime('%H:%M:%S')}")
                    self.reminded_today = True
                    self.show_vibrant_popup()
                
                time.sleep(self.check_interval)  # Check every 5 minutes
                
        except KeyboardInterrupt:
            print("\nClock-in reminder stopped.")

if __name__ == "__main__":
    reminder = ClockInReminder()
    reminder.run()