import drawio

# Define the diagram structure
diagram = {
    "name": "Chatbot for Government Officers",
    "cells": [
        {
            "id": "1",
            "value": "Rule-Based Expert Chatbot for Government Rules",
            "style": {
                "shape": "rectangle",
                "fillColor": "#ffffff",
                "strokeColor": "#000000",
                "fontSize": "16",
                "fontWeight": "bold"
            }
        },
        {
            "id": "2",
            "value": "Purpose",
            "style": {
                "shape": "rectangle",
                "fillColor": "#ffff00",
                "strokeColor": "#000000",
                "fontSize": "14",
                "fontWeight": "normal"
            }
        },
        {
            "id": "3",
            "value": "Problem Description",
            "style": {
                "shape": "rectangle",
                "fillColor": "#ffff00",
                "strokeColor": "#000000",
                "fontSize": "14",
                "fontWeight": "normal"
            }
        },
        # Add other shapes and connections here
        # ...
    ]
}

# Generate the Draw.io XML
drawio_xml = drawio.drawio_export(diagram)

# Print the XML (optional)
print(drawio_xml)

# Save the XML to a file
with open("mind_map.xml", "w") as file:
    file.write(drawio_xml)
