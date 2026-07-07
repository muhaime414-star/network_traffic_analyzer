import socket
import struct
import textwrap

def main():
	conn= socket.socket(socket.AF_PACKET,socket.SOCK_RAW,socket.ntohs(3))
	print("Listening for traffic~~~~~~")

	while True:
		raw_data,addr=conn.recvfrom(65536)

		dest_mac,src_mac,eth_proto,data=parse_ethernet_fram(raw_data)
		print('\n' + '=' *50)
		print(f'Ethernet frame:')
		print(f'  Destination MAC: {dest_mac}')
        print(f'  Source MAC:      {src_mac}')
        print(f'  Protocol:        {eth_proto}')

    def parse_ethernet_frame)data:
	dest,src,prototype= struct.unpack ('6s 6s H',data[:14])
	return format_mac_addr(dest), format_mac_addr(src), socket.htons(prototype), data[14:]


	def format_mac_addr(bytes_addr):
    	bytes_str = map('{:02x}'.format, bytes_addr)
    	return ':'.join(bytes_str).upper()

if __name__ == '__main__':
    main()