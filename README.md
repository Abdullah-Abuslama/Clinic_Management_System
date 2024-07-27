# Clinic Management System

This C code implements a clinic management system. The system provides two modes of operation: admin mode and user mode.

## Admin Mode

### Features:

1. **Add New Patient Record**
   - Admin enters the patient's name, age, gender, and ID.
   - The ID must be unique. If the ID already exists, the system rejects the entry.

2. **Edit Patient Record**
   - Admin enters the patient ID to edit the patient's information.
   - If the ID does not exist, the system displays an incorrect ID message.

3. **Reserve a Slot with the Doctor**
   - Five available slots by default: 
     - 2pm to 2:30pm
     - 2:30pm to 3pm
     - 3pm to 3:30pm
     - 4pm to 4:30pm
     - 4:30pm to 5pm
   - The system displays available slots.
   - Admin enters the patient ID and desired slot.
   - Reserved slots do not appear again for subsequent reservations.

4. **Cancel Reservation**
   - Admin enters the patient ID to cancel a reservation.
   - The canceled slot is shown again in the available slots window.

### Admin Mode Entry
- Password is required. Default password: `1234`.
- Allows 3 attempts for password entry. After 3 incorrect attempts, the system closes.

## User Mode

### Features:

1. **View Patient Record**
   - User enters the patient ID to view basic information.

2. **View Today's Reservations**
   - Displays all reservations with patient IDs attached to each reservation slot.
