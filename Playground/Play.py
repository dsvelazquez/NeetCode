import graphviz

# Create the diagram as a directed graph
usb_diagram = graphviz.Digraph(format='png')
usb_diagram.attr(rankdir='LR', size='10')

# Nodes
usb_diagram.node("Host", "USB Host (PC)")
usb_diagram.node("Device", "USB HID Device (MCU)")
usb_diagram.node("USB_Event_Handler", "APP_USBDeviceEventHandler")
usb_diagram.node("HID_Event_Handler", "APP_USBDeviceHIDEventHandler")
usb_diagram.node("App_State", "Application Logic / State Machine")
usb_diagram.node("HID_Report", "HID Report (Key, Button, etc.)")

# Edges
usb_diagram.edge("Host", "Device", label="USB Events\n(e.g., Set Config, Suspend)")
usb_diagram.edge("Device", "USB_Event_Handler", label="Pass to handler")
usb_diagram.edge("USB_Event_Handler", "HID_Event_Handler", label="Register HID Handler")
usb_diagram.edge("Host", "HID_Event_Handler", label="HID Events\n(Get/Set Idle, Report)", style="dashed")
usb_diagram.edge("HID_Event_Handler", "App_State", label="Set flags\n(e.g., isReportReceived)")
usb_diagram.edge("App_State", "HID_Report", label="Prepare report\n(data to send)")
usb_diagram.edge("HID_Report", "HID_Event_Handler", label="Send report")
usb_diagram.edge("HID_Event_Handler", "Host", label="Report Sent ACK", style="dashed")

# Render the file
usb_diagram.render("usb_hid_flow", cleanup=True)
