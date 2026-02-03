from mininet.net import Mininet
from mininet.node import Controller, OVSSwitch, Host
from mininet.cli import CLI
from mininet.link import TCLink

def create_topology():
    net = Mininet(controller=Controller, switch=OVSSwitch, link=TCLink)

    # Add hosts, switches, and links
    h1 = net.addHost('h1')
    h2 = net.addHost('h2')
    s1 = net.addSwitch('s1')

    net.addLink(h1, s1)
    net.addLink(h2, s1)

    net.start()
    CLI(net)
    net.stop()

if __name__ == '__main__':
    create_topology()

