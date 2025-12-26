def get_feature_status (self, testscript, hdl, feature):
      
        cfg = '''
            show feature | grep   {0}
            '''.format(feature)

        try:
            output = hdl.execute(cfg)
        except:
            log.error('Invalid CLI given: %s' % (cfg))
            log.error('Error with cli')
            log.error(sys.exc_info())
            self.failed()
        for k, v in output.items():
            if not v:
                continue
            else :
                break 
        log.info(v)
        log.info( type(v))
        v = " ".join(v.split())
        li = list(v.split(" "))
        log.info (li)
        return(li[2])
