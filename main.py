import sys
import smtplib

def send_email(email, otp):
    smtp_server = 'smtp.gmail.com'  # SMTP server for Gmail
    smtp_port = 587  # SMTP port for TLS
    sender_email = 'rk0905543@gmail.com'
    sender_password = '' #your app password

    # Create an SMTP connection
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()

    # Login to your email account
    server.login(sender_email, sender_password)

    # Compose the email
    subject = 'OTP Verification'
    message = f'Your OTP is: {otp}'
    msg = f'Subject: {subject}\n\n{message}'

    # Send the email
    server.sendmail(sender_email, email, msg)

    # Close the SMTP server
    server.quit()

if __name__ == "__main__":
    recipient_email = sys.argv[1]
    otp = sys.argv[2]
    send_email(recipient_email, otp)
